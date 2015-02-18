//a1
void func()
{
	int h1, m1, s1, h2, m2, s2;
	cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
	int t1 = 3600 * h1 + 60 * m1 + s1;
	int t2 = 3600 * h2 + 60 * m2 + s2;
	int t3 = abs(t2 - t1);
	int t4 = t3 % 3600;
	cout << t3 / 3600 << ":" << (t4/60) << ":" << (t3 % 3600) % 60 << endl;

}
int main()
{
	func();
	return 0;

}