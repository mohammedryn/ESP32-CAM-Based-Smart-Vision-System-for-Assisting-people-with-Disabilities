% Read image
img = imread('scene.jpg'); % use a test image

% Resize for ESP32-like resolution
img = imresize(img, [240 320]);

% Convert to grayscale
gray = rgb2gray(img);

% Convert to double for processing
gray = double(gray);

% Apply Sobel Edge Detection
Gx = [-1 0 1; -2 0 2; -1 0 1];
Gy = [-1 -2 -1; 0 0 0; 1 2 1];

Ix = conv2(gray, Gx, 'same');
Iy = conv2(gray, Gy, 'same');

% Magnitude
Gmag = sqrt(Ix.^2 + Iy.^2);

% Color detection (Red)
R = img(:,:,1);
G = img(:,:,2);
B = img(:,:,3);
redMask = (R > 200) & (G < 50) & (B < 50);

% Visualize
subplot(1,3,1), imshow(img), title('Original');
subplot(1,3,2), imshow(Gmag, []), title('Edges');
subplot(1,3,3), imshow(redMask), title('Red Object Mask');
