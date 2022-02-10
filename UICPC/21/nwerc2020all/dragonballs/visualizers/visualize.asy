import fontsize;

int w = 100;
int h = 100;

size(1000, 1000);

defaultpen(3 + grey);

pen grid = linewidth(0.5) + RGB(20,20,20);

// Draw a grid
for (int i = 0; i <= h; i += 1) {
	draw((0,i) -- (w, i), grid);
}
for (int j = 0; j <= w; j += 1) {
	draw((j,0) -- (j, h), grid);
}

layer();

pen border = linewidth(3.5);
pen f = linewidth(1);


// Draw queries
int q = stdin;
for (int qi = 0; qi < q; ++qi){
	int x = stdin;
	int y = stdin;
	int a = stdin;
	int b = stdin;

	draw((x,y) -- (a,b), (1.0*qi/q * green + (1-1.0*qi/q)*black));
	dot((x,y), border + black, Fill(f + blue));
}

// Draw Balls

int n = stdin;
for (int i = 0; i < n; ++i){
	int x = stdin;
	int y = stdin;

	dot((x,y), border + red, Fill(f + red));
}

shipout(bbox(xmargin=30, ymargin=30, white, Fill));
