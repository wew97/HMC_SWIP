function y = findSum(x)
    % persistent => 변수가 남아있음
    % persistent SUM_X
    global SUM_X
    
    if isempty(SUM_X)
        SUM_X = 0;
    end
    
    SUM_X = SUM_X + x;
    y = SUM_X;

end