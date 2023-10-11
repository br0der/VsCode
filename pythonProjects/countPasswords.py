from functools import cache


# A Dynamic Programming method which takes in 'remaining', 
# how many repeated letters are still required to be added,
# and a curr_length, which represents how long our imaginary
# string is.

# This method returns how many strings we can build with
# these parameters.

# Cached because answer will always be the same, given the
# same parameters.
@cache 
def func(remaining, curr_length): 
    # Our base case of having a full string.
    if curr_length>=8:
        # If we do not have any more repeated letters
        # required, we return 1.
        if remaining==0:
            return 1
        else:
            return 0
    out = 0
    if remaining!=0:
        # If we still have remaining letters required,
        # we can either add a repeated letter or add a 
        # random letter, which we have 25 options for.
        out+=func(remaining-1, curr_length+1)
        out+=func(remaining, curr_length+1)*25
    else:
        # If we do not need to add any remaining letters,
        # we add any of the 26 letters. This also guarentees
        # that there is a chance we cover edge cases like 
        # AAAAAAAA
        out+=func(remaining, curr_length+1)*26
    return out

# We start by stating that we need to cover a minimum of
# 5 repeated letters, and we start with an empty string.

# Because our function only imagines one letter being repeated,
# we multiply by 26 to simulate doing this 26 times for all
# letters
print(func(5, 0)*26)