-- this will be init from c++
width = 80
height = 60
-- array of pixels
-- (y * width) + x is used to convert positions
-- from array to matrix
pixel_matrix = {}

-- init matrix
h = 1
w = 1

while (h <= height) 
do
	while(w <= width) 
	do
		pixel_matrix[(h * width) + w] = 0
		w = w + 1
	end
	h = h + 1
	w = 1
end

function draw(start_x, start_y, end_x, end_y)
	-- bresenhams algorithm
	-- draw east
	step_y = 1
	if(end_y < start_y) then step_Y = -1 end

	dx = end_x - start_x;
	dy = math.abs(end_y - start_y);

	lambda = 2 * dy - dx;
	incr1 = 2 * dy;
	incr2 = 2* (dy - dx);

	curr_x = start_x
	curr_y = start_y

	-- we draw a pixel by marking it with 1 in matrix
	pixel_matrix[(curr_y * width) + curr_x] = 1;

	while (curr_x < end_x) do 
		curr_x = curr_x + 1
		if (lambda <= 0) then
			lambda = lambda + incr1
		else
			lambda = lambda + incr2
			curr_y = curr_y + step_y
		end
		pixel_matrix[(curr_y * width) + curr_x] = 1;
	end
end
