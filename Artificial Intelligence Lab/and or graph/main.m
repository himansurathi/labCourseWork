[adj_mat,and_mat,heuristic_mat,start_node,goal_node,vertices,edges] = read_data();
[val,heuristic_updated] = update_heuristic( adj_mat,and_mat,vertices,edges,heuristic_mat,1)

found = sahc(adj_mat,and_mat,heuristic_updated,start_node,goal_node,vertices);
fprintf(1,'found = %d\n',found)