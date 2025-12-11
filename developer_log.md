# Developer Log

- 12/07 
  - Set up the repo today and fixed some 
  CMakeLists.txt(configuration) issues. Looked through the assignment and 
  main.cpp to understand the task. I make it out to be that im
  making the foundation of the story and connecting nodes
  to one another. Also for future notice, remember to ensure
  the nodes are pointed somewhere. RE-did the 
  node structure in tree.h as it was calling for string
  and U instead of int and T. Still understanding the layout
  so I just added a map in the Tree class for storing nodes.
  No logic today, hoping to add that tmr.daw

- 12/09
  - Started working on the actual functions today instead of just reading
    everything. Added the Tree constructor and createRoot so I could at least
    build the start of the story. Messed around with addNode and tried linking
    children to parents. Kept running into issues with the nodes not connecting
    the way I expected but I think I’m starting to understand how the ID system
    works. Didn’t finish everything but it's starting to make sense now.

- 12/10
  - Today I spent pretty much the whole time actually finishing the Tree functions. I
    implemented createRoot, addNode, findNode using DFS, printAll, and the destructor
    inside tree.h. Most of this part was me trying to understand how the nodes
    are supposed to link together and making sure everything was dynamically allocated
    the right way. After that, I started building the tree using the rawNodes from main. The first big
    bug I hit was that every child node was showing the same text as the parent. I found
    out this was because I was passing rawNodes[i].text instead of the child’s actual
    text. I fixed that by searching through rawNodes to grab the correct text for each
    child ID before passing it into addNode. Once that worked, the next issue was that the program couldn’t find story.txt. I kept
    getting “story empty or invalid.” I figured out CLion was running the program inside
    the cmake-build-debug folder, so the file wasn’t being read at all. I fixed that by
    copying story.txt into that folder so the program could finally parse it. Then I checked printAll,
    and it printed the nodes but the order looked backwards. It
    turned out to be because I'm using unordered_map which doesn’t keep things ordered. I was too
    lazy so I grabbed all the IDs, put them into a vector, sorted them, and printed in
    sorted order. After all that, I tested playGame and it worked. It showed the correct choices and
    moved through the story the right way. At this point the tree builds correctly, prints
    correctly, and the gameplay works.

  - Files I worked on today: tree.h, tree.cpp, main.cpp
    and story.txt for testing.