int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{

	int	l, r, u, d;

	l = A >= E ? A : E;
	r = C <= G ? C : G;
	u = D <= H ? D : H;
	d = B >= F ? B : F;
	if (l >= r || d >= u)
		return((D - B) * (C - A) + (H - F) * (G - E));
	else
		return((D - B) * (C - A) + (H - F) * (G - E) - (r - l) * (u - d));
}

int main(void)
{
}
