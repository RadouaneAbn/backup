
Example: vc = [9, 5, 1, 8, 4, 3]

STEP 1: vc = [9, 5, 1, 8, 4, 3]             // vector
      : ps = [[9, 5], [1, 8], [4, 3]] + []  // make pairs
      : ps = [[5, 9], [1, 8], [3, 4]] + []  // sort pairs

STEP 2: mc = [9, 8, 4]                      // create main chain

rec++> sort the main chain (recursion)
 
STEP 1: vc = [9, 8, 4]
      : ps = [[9, 8]] + [4]
      : ps = [8, 9] + [4]

STEP 2: mc = [9]

rec++>

vc size is one so return

rec-->

STEP 3:
    vc = [9, 8, 4]
    ps = [8, 9] + [4]
    mc = [9]

    pnd = [8]
    prt = [9]

    STEP 4: add the first pending to main chain
        mc  = [8, 9]

    STEP 5: insert remaining pending to main chain
        jc_sec = [0]
        inserted = [true]
    
        // handle missed pending elements
        // nothing to do

        STEP 6:
        mc = [4, 8, 9]
        vc = main_chain

rec-->

STEP 3:
    vc = [9, 5, 1, 8, 4, 3]
    ps = [[5, 9], [1, 8], [3, 4]] + []
    STEP 2: mc = [4, 8, 9] <= [9, 8, 4]

    pnd = [3, 1, 5]
    prt = [4, 8, 9]

    STEP 4:
        mc = [3, 4, 8, 9]

    STEP 5:
        js_sec = [0, 1, 1]
        inserted = [true, true, false]

        mc = [1, 3, 4, 8, 9]


