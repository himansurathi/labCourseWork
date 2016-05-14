% Takes in an array!

function cost = heuristic(state)
    returnValue = 0;
    
    for i = 1:length(state)
        if i ~= state(i)
            returnValue = returnValue + 1;
        end
    end

    cost = returnValue;
end

