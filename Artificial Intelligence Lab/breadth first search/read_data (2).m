function [adj_mat,start_node,end_node,vertices,edges] = read_data()

%% Load graph data
fid = fopen('input.txt');
inp_cell = textscan(fid,'%d %d');
inp = cell2mat(inp_cell);
vertices = inp(1,1);
edges = inp(1,2);
start_node = inp(2,1)
end_node = inp(2,2)
graph= inp(3:length(inp),:);
fclose(fid);

%% Store graph data into adjacency matrix
adj_mat = zeros(vertices);
for i = 1: edges
    x= graph(i,1);
    y= graph(i,2);
    adj_mat(x,y)=1;
    %adj_mat(y,x)=1;
end


end

