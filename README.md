Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

  
  
  First algorithm:
    First described by Kahn (1962), works by choosing vertices in the same order as the eventual topological sort. First, find a list of "start nodes" which have no incoming edges and insert them into a set S; at least one such node must exist in a non-empty acyclic graph. Then:

         L ← Empty list that will contain the sorted elements

         S ← Set of all nodes with no incoming edge

         while S is non-empty do
    
            remove a node n from S
    
            add n to tail of L
    
          for each node m with an edge e from n to m do
       
            remove edge e from the graph
        
            if m has no other incoming edges then
            
                insert m into S

          if graph has edges then
    
                return error (graph has at least one cycle)

          else 
   
               return L (a topologically sorted order)



Code for this algo can be found in toposort.cpp file.    
    


Second algorithm:
    An alternative algorithm for topological sorting is based on depth-first search. The algorithm loops through each node of the graph, in an arbitrary order, initiating a depth-first search that terminates when it hits any node that has already been visited since the beginning of the topological sort or the node has no outgoing edges (i.e. a leaf node):

        L ← Empty list that will contain the sorted nodes
        while there are unmarked nodes do
            select an unmarked node n
            visit(n) 
        function visit(node n)
          if n has a temporary mark then stop (not a DAG)
          if n is not marked (i.e. has not been visited yet) then
            mark n temporarily
            for each node m with an edge from n to m do
              visit(m)
            mark n permanently
            unmark n temporarily
            add n to head of L
        
   
   
   code for this algo can be found in toposortbydfs.cpp  file.     
