function edgeImage = sobel(originalImage, threshold)
    assert(all(size(originalImage) <= [1024 1024]));
    assert(isa(originalImage,'double'));
    assert(isa(threshold, 'double'));
    
    k = [1 2 1; 0 0 0; -1 -2 -1];
    H = conv2(double(originalImage),k,'same');
    V = conv2(double(originalImage),k','same');
    E = sqrt(H.*H + V.*V);
    edgeImage = uint8((E > threshold) * 255);
end