%%
[adj_mat,start_node,end_node,vertices,edges] = read_data();
adj_mat
found = sahc(adj_mat,start_node,end_node,vertices);
if found==1
    fprintf(1,'Found!\n')
else
    fprintf(1,'Not Found!\n')
end