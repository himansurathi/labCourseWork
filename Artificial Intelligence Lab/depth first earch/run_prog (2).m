% %%
% [adj_mat,start_node,end_node,vertices,edges] = read_data();
% found = bfs(adj_mat,start_node,end_node,vertices,edges);
% fprintf(1,'%d\n',found)

%%
%[adj_mat,start_node,end_node,vertices,edges] = read_data();
%found = dfs(adj_mat,start_node,end_node,vertices,edges);
%fprintf(1,'%d\n',found)

%%
[adj_mat,start_node,end_node,vertices,edges] = read_data();
found = dfs(adj_mat,start_node,end_node,vertices);
fprintf(1,'%d\n',found)