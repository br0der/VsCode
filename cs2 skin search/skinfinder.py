from bitskinsapi import getMedianSellBitskins, getName, getMinSellBitskins
from steamapi import getPrice, getMinSellSteam

# Steam takes 13%

mode = 'sell'

discount = 0 if mode=='sell' else 0

mult = 8

skins = getName("", lim=100, offs=0, discountLow=discount, discountHigh=10)
# skins.extend(getName("Gloves", lim=5*mult, offs=0, discountLow=discount))
# skins.extend(getName("Bayonet", lim=1*mult, offs=0, discountLow=discount))
# skins.extend(getName("Karambit", lim=1*mult, offs=0, discountLow=discount))
value = []


names = set()
for i in range(len(skins)):
    
    if skins[i][0] in names:
        continue
    if mode=='buy':
        bitskins = skins[i][2]/1000
    if mode=='sell':
        bitskins = getMinSellBitskins(skins[i][0])

    if bitskins==None:
        print(f"Bitskins error: {skins[i][0]}")
        continue
    skins[i].append(bitskins)
    print('Bitskins done')

    if mode=='buy':
        steam = getMedianSellBitskins(skins[i][1])
    if mode=='sell':
        steam = getMinSellSteam(skins[i][0])

    if steam==None:
        print(f"Steam error: {skins[i][0]}")
        continue
    skins[i].append(steam)
    print('Steam done')
    if mode=='buy':
        value.append([((skins[i][4]/skins[i][3])-1)*100, skins[i][0], skins[i][3], skins[i][4]])
    if mode=='sell':
        value.append([((skins[i][3]/skins[i][4])-1)*100, skins[i][0], skins[i][4], skins[i][3]])
    names.add(skins[i][0])
    print(i)

value.sort(key=lambda x: -x[0])
for skin in value:
    print(skin)