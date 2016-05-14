% Reconstruct and display the path from the given node to the root of the tree.
% -- arguments --
% node: the current node in the tree, must be of class puzzle.

function path = reconstruct_path(node)
    % total_path = current
    % while current in tree
    path(1) = node;
    i = 2;
    
    while ~isempty(node.parent)
        % current = current.parent
        node = node.parent;
        % total_path.append(current)
        path(i) = node;
        i = i + 1;
    end
    
    %print total path
    path = fliplr(path); %flip to get correct descent down tree from initial to goal state

    for i = 1:length(path)
        k= int2str(path(i).state);
        pos= findstr(k,'9');
        k(1,pos)='$';
        j=1;
        while(j+2<=length(k))
            disp(k(1:1,j:j+2))
            j=j+3;
        end
        fprintf(1,'\n======\n')
        %disp(path(i).state)
    end
end