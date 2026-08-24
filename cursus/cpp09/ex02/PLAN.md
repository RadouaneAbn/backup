




func sort_pair(a, b):
    if a < b:
        return (a, b)
    return (b, a)

func sortContainer(container):
    container_size = container.size()
    if container_size < 1:
        return

    left_over = -1;
    if container_size % 2: // if the size of the container is odd
        left_over = container.last()
        container.pop_last()

    // STEP 1: pair the elements of the container as a sorted pairs
    // [(b1,a1), (b2,a2), ...] with b < a
    pairs = []
    i = 0
    while i < container_size:
        pairs.append(sort_pair(container[i], container[i + 1]))

    // STEP 2: Sort main chain recursively, second element of all pairs
    main_chain = []                         // all a's [a1, a2, ...]
    for pair in pairs:
        main_chain.append(pair[1])
    sortContainer(main_chain)

    // STEP 3: realign pending elements with the sorted main chain
    pending = []                            // all b's
    partners = []                           // all a's
    for elem in main_chain:
        for pair in pairs:
            if elem == pair[1]:
                pending.append(pair[0]);    // b
                partners.append(pair[1]);   // a
                break
    
    main_chain.insert(0, pending[0])
            
