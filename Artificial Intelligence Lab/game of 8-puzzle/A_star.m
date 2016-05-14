function elasped_time = A_star(starting_node,goal)
    tic % start timer
    goal_state = goal;
    closed(1) = puzzle; closed(1) = []; % initialize empty puzzle array
    open(1) = puzzle; open(1) = []; % initialize empty puzzle array

    starting_node.f_score = starting_node.g_score + heuristic(starting_node.state);
    open = starting_node;

    while ~isempty(open) % while openset is not empty
        current = open(1);
        current_index = 1;

        % set current as the node with the lowest f_score
        for i=1:length(open)
            if open(i).f_score < current.f_score
                current = open(i);
                current_index = i;
            end
        end
        
        if current.state == goal_state
            reconstruct_path(current);            
            elasped_time = toc %show elapsed time
            return
        end
        
        open(current_index) = []; % remove current from openset
        closed(length(closed) + 1) = current; % add current to closedset
        
        % initialize empty puzzle array
        neighbors(1) = puzzle; neighbors(1) = [];
        
        % move blank left
        validNeighbor = true;
        nodeMoveLeft = moveBlankLeft(current);
        for i=1:length(closed)
            if isequal(closed(i).state, nodeMoveLeft.state)
                validNeighbor = false;
                break;
            end
        end
        if validNeighbor == true
            nodeMoveLeft.parent = current;
            nodeMoveLeft.g_score = current.g_score + 1;
            neighbors(length(neighbors) + 1) = nodeMoveLeft;
        end
        
        % move blank right
        validNeighbor = true;
        nodeMoveRight = moveBlankRight(current);
        for i=1:length(closed)
            if isequal(closed(i).state, nodeMoveRight.state)
                validNeighbor = false;
                break;
            end
        end
        if validNeighbor == true
            nodeMoveRight.parent = current;
            nodeMoveRight.g_score = current.g_score + 1;
            neighbors(length(neighbors) + 1) = nodeMoveRight;
        end
        
        % move blank down
        validNeighbor = true;
        nodeMoveDown = moveBlankDown(current);
        for i=1:length(closed)
            if isequal(closed(i).state, nodeMoveDown.state)
                validNeighbor = false;
                break;
            end
        end
        if validNeighbor == true
            nodeMoveDown.parent = current;
            nodeMoveDown.g_score = current.g_score + 1;
            neighbors(length(neighbors) + 1) = nodeMoveDown;
        end
        
        % move blank up
        validNeighbor = true;
        nodeMoveUp = moveBlankUp(current);
        for i=1:length(closed)
            if isequal(closed(i).state, nodeMoveUp.state)
                validNeighbor = false;
                break;
            end
        end
        if validNeighbor == true
            nodeMoveUp.parent = current;
            nodeMoveUp.g_score = current.g_score + 1;
            neighbors(length(neighbors) + 1) = nodeMoveUp;
        end
        
        % for each neighbor
        for i=1:length(neighbors)
            ineighbor = neighbors(i);
            inOpen = false;
            for j=1:length(open)
                if ineighbor.state == open(j).state
                    inOpen = true;
                end
            end
            
            if inOpen == false
                neighbor = neighbors(i);
                neighbors(i).f_score = neighbor.g_score + heuristic(neighbor.state);
                open(length(open) + 1) = neighbors(i);
            end
        end        

    end % while
end % function