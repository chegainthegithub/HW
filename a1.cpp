//a1
#include 
int h3, m3, s3;
using namespace std;
void func(int h1, int m1, int s1, int h2, int m2, int s2)
{
	s3 = s2 - s1;
	if (s3 < 0)
	{
		s3 = 60 + s3;
		m2 = m2 - 1;
	}
	m3 = m2 - m1;
	if (m3< 0)
	{
		m3 = 60 + m3;
		h2 = h2 - 1;
	}
	h3 = h2 - h1;
}
int main()
{
	int h1, m1, s1, h2, m2, s2;
	cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
	func(h1, m1, s1, h2, m2, s2);
	cout << h3 << " " << m3 << " " << s3 << endl;
}