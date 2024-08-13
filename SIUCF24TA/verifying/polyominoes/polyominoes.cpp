//Solution for polyominoes
//Thomas Meeks


//This is very much an implementation problem and i am not sorry for making it.
//The main idea is to build each Degree N+1 polyomino from the preceeding
//Degree N polyominoes. To avoid double counting we need to canonicalize
//that means for any given polyomino that is the same as another we need to
//transform them both into the same representitive polyomino
//since in this solution the polyomonioes are represented by a unsigned long long
//and are on an 8 by 8 grid a form of canonicalization we can use
//is all reflections and rotations, shift the shape to an arbitary corner
//and then for all of those resulting masks we will use the mask with the
//minimum numeric value, minimum is arbitary it could also be maximum
//we will need alot of helper functions to handle all of the bitwise operations needed for moving the mask

//if you don't fully understand bitwise operations i highly reccomend learning them before trying
//to decipher this code.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//the 64 bit unsigned long long represented an 8by8 grid in row major order
typedef unsigned long long ull;

//get a particular cell in the grid (from it's mask form)
inline bool get(int r, int c, ull &mask){
    return mask & (1ul << ((r*8)+c));
}

//set a particular cell in the grid (from it's mask form)
inline void setM(int r, int c, ull &mask){
    mask |= (1ul << ((r*8)+c));
}

//clear a particular cell in the grid (from it's mask form)
inline void clearM(int r, int c, ull &mask){
    mask &= ~(1ul << ((r*8)+c));
}

//helper function for displaying a grid, only used for debugging
void display(ull mask){
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            if(get(r,c,mask)) cout << "X";
            else cout << "O";
        }
        cout << "\n";
    }
}
//a whole lot of global variables 
ull maskExpand[256];
ull mask8Reflect[256];
const int sizeSquare = 1<<16;
ull squarePreComp[sizeSquare];
ull borderRing = 0;
ull lastBitMask = 0;
ull firstBitMask = 0;
ull leftBorder = 0;
ull rightBorder = 0;
ull topBorder = 0;
ull bottomBorder = 0;

//allows us to do rotations in "8" operations rather than 64, the rotation ends up being
//taking each group of 8 bits and expanding them out to be a fully mask, each group has a different offset
//we have an array of precomped bit expansions.
void rotate(ull &mask){
    ull newMask = 0;
    ull eightMask = (1<<8)-1;
    for(int groupIndex = 0; groupIndex < 8; groupIndex++){
        ull groupMask = ((mask >> (groupIndex * 8)) & eightMask);
        newMask |= (maskExpand[groupMask] << groupIndex);
    }
    mask = newMask;
}
//implace and function versions of shift up and shiftdown because i could't decide which one i was using
void shiftDown(ull &mask, int rows = 1){ mask = (mask << (8*rows));  }
void shiftUp(ull &mask, int rows = 1) {mask = (mask >> (8*rows)); }
ull shiftedUp(ull mask, int rows = 1) {mask = (mask >> (8*rows)); return mask; }
ull shiftedDown(ull mask, int rows = 1){ mask = (mask << (8*rows)); return mask;  }
//when shifting right or left we first clear the bits at the end so they don't move to the next row.
void shiftRight(ull &mask, int cols = 1){
    mask &= ~(lastBitMask);
    mask <<= (cols);
}

void shiftLeft(ull &mask, int cols = 1){
    mask &= ~(firstBitMask);
    mask >>= (cols);
}

ull shiftedRight(ull mask, int cols = 1){
    mask &= ~(lastBitMask);
    mask <<= (cols);
    return mask;
}

ull shiftedLeft(ull mask, int cols = 1){
    mask &= ~(firstBitMask);
    mask >>= (cols);
    return mask;
}

//flipping each group of 8
void reflectVerticle(ull &mask){
    ull newMask = 0;
    ull mask8 = (1<<8)-1;
    newMask |= (((mask8) & mask) << 56);
    newMask |= (((mask8<<8) & mask) << 40);
    newMask |= (((mask8<<16) & mask) << 24);
    newMask |= (((mask8<<24) & mask) << 8);

    newMask |= (((mask8<<56) & mask) >> 56);
    newMask |= (((mask8<<48) & mask) >> 40);
    newMask |= (((mask8<<40) & mask) >> 24);
    newMask |= (((mask8<<32) & mask) >> 8);
    mask = newMask;
}
//i thought i needed both reflections
//you actually only need one reflection so this is useless
void reflectHorizontal(ull &mask){
    ull newMask = 0;
    ull mask8 = (1<<8)-1;
    for(int i = 0; i < 8; i++){
        newMask |= mask8Reflect[(mask>>(i*8))&mask8] << (i*8);
    }
    mask = newMask;
}

void precomp(){
    //memset our arrays to zero because it helps me sleep better at night
    memset(maskExpand,0,sizeof(maskExpand));
    memset(mask8Reflect,0,sizeof(mask8Reflect));
    memset(squarePreComp,0,sizeof(squarePreComp));

    //make mask for the first and last bit of each row for left and right shift clearing
    for(int i = 0; i < 8; i++) firstBitMask |= (1ul << (i*8));
    for(int i = 0; i < 8; i++) lastBitMask |= (1ul << ((i*8)|7));
    
    //i promise this is a square <3
    ull square = 3|(3<<8);
    //ok basically instead of looking through all spots in the grid looking for a square we can
    //precomp 2 rows (2^16 = 65536) and now we only need to check 7 array slots when looking for a square
    for(int mask = 0; mask < (1<<16); mask++){
        for(int i = 0; i < 7; i++){
            if(((square << i) & mask) == (square << i)) squarePreComp[mask] = true; 
        }
    }

    //lord forgive me
    for(int mask = 0; mask < (1<<8); mask++){
        //not the shortest way of doing this but copy and paste go brrr
        ull bit0 = (bool)(mask & (1<<0));
        ull bit1 = (bool)(mask & (1<<1));
        ull bit2 = (bool)(mask & (1<<2));
        ull bit3 = (bool)(mask & (1<<3));
        ull bit4 = (bool)(mask & (1<<4));
        ull bit5 = (bool)(mask & (1<<5));
        ull bit6 = (bool)(mask & (1<<6));
        ull bit7 = (bool)(mask & (1<<7));
        //useless reflection mask that i didn't even need
        mask8Reflect[mask] =(bit7 << 0)  | (bit6 << 1)  |
                            (bit5 << 2)  | (bit4 << 3)  |
                            (bit3 << 4)  | (bit2 << 5)  |
                            (bit1 << 6)  | (bit0 << 7);
        //expand out the mask for the rotation earlier in the code
        maskExpand[mask] =  (bit7 << 0)  | (bit6 << 8)  |
                            (bit5 << 16) | (bit4 << 24) |
                            (bit3 << 32) | (bit2 << 40) |
                            (bit1 << 48) | (bit0 << 56);
    }
    //border ring ends up not being needed
    for(int c = 0; c < 8; c++){
        setM(0,c,borderRing);
        setM(7,c,borderRing);
        setM(0,c,topBorder);
        setM(7,c,bottomBorder);
    }

    for(int r = 0; r < 8; r++){
        setM(r,0,borderRing);
        setM(r,7,borderRing);
        setM(r,0,leftBorder);
        setM(r,7,rightBorder);
    }
}


ull moveToCorner(ull mask){
    //we are gonna keep moving the mask to the left and down until it hits the border
    //once it gets to the border we will push it back up so it's not on the edge and
    //new cells can still be placed around it
    while((mask & leftBorder) == 0){ shiftLeft(mask); }
    while((mask & bottomBorder) == 0) shiftDown(mask);
    if(mask & leftBorder) shiftRight(mask);
    if(mask & bottomBorder) shiftUp(mask);
    return mask;
}
//what a nightmare
ull minTransformation(ull mask){
    ull res = ULLONG_MAX;
    //rather clunky since i decided to make this pass by reference
    ull reflection = mask; reflectVerticle(reflection);
    mask = moveToCorner(mask);
    //always move to corner before minning result!!
    res = min(min(res,moveToCorner(mask)),moveToCorner(reflection));
    rotate(mask); res = min(res,moveToCorner(mask));
    rotate(mask); res = min(res,moveToCorner(mask));
    rotate(mask); res = min(res,moveToCorner(mask));
    rotate(reflection); res = min(res,moveToCorner(reflection));
    rotate(reflection); res = min(res,moveToCorner(reflection));
    rotate(reflection); res = min(res,moveToCorner(reflection));
    return res; //which ever result is the smallest was the canonical representation
}

bool valid(ull mask){
    mask = moveToCorner(mask);
    if((mask & leftBorder) || (mask & rightBorder)) return false;
    if((mask & topBorder) || (mask & bottomBorder)) return false;
    //return true;
    //speedy square check because of precomp
    ull mask16 = (1<<16)-1;
    for(int i = 0; i < 7; i++){
        if(squarePreComp[mask16 & (mask >> (i*8))]) return false;
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("thomas.out","w", stdout);
    #endif
    //precomppppp
    precomp();
    //tis is where all the magic happens
    int n; cin >> n;
    vector<vector<ull> > results(n+1);
    ull startingGuy = 0; 
    setM(4,4,startingGuy);
    startingGuy = minTransformation(startingGuy); //maybe uneccesary but :shrug:
    results[1].push_back(startingGuy); //the starting guy
    vector<int> ans(n+1); ans[1] = 1; 
    //now that we have all of our helper functions the code from here is pretty easy
    for(int degree = 2; degree <= n; degree++){
        for(ull poly: results[degree-1]){
            ull neighbors = 0;  //bit mask of all valid neighbors
            //well a neighbor has to be next to the current poly so lets just shake it around
            neighbors |= shiftedDown(poly);
            neighbors |= shiftedUp(poly);
            neighbors |= shiftedLeft(poly);
            neighbors |= shiftedRight(poly);
            neighbors &= ~(poly); //we can't place a square on ourselves so lets get rid of that

            //might be a better way of doing this but you can have tons of neighbors anyway
            for(int i = 0; i < 64; i++){
                if(neighbors & (1ul << i)){
                    ull newPoly = poly|(1ul<<i);
                    if(!valid(newPoly)) continue; //if the newpolygon isn't valid lets not add it to our list

                    newPoly = minTransformation(newPoly); //find canonical representation
                    results[degree].push_back(newPoly); //lets goooo
                }
            }
        }

        sort(results[degree].begin(),results[degree].end());
        //after items are sorted there is built in functions to uniqueify the vector
        results[degree].erase(unique(results[degree].begin(),results[degree].end()),results[degree].end());
        ans[degree] = results[degree].size(); //we found our answer
        if(degree-1 >= 0) results[degree-1].clear(); 
        //lets just get rid of these guys to save memory not that big of deal since the growth is exponential but
        //save the turles amirite
        //for(auto el: results[degree]) { display(el); cout << '\n'; }
        //cout << degree << " " << ans[degree] << "\n";
        //int x; cin >> x;
    }
    sort(results[n].begin(), results[n].end());
    // display(results[12][0]);
    for(int i = 0; i < results[n].size(); i++){
        cout << results[n][i] << endl;
    }
    //oh look we can now print the answer
    // for(int i = 1; i< ans.size(); i++) cout << ans[i] << "\n";
    // return 0;
}