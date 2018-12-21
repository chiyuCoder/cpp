class AString
{
  public:
	int BfFind(AString &pat, int k) const {
		int i, j;
		for (i = k; i < length - pat.length; i ++)
		{
			for (j = 0; j < pat.length; j ++)
			{
				if (ch[i+j] != pat.ch[i+j]) {
					break;
				}
			}
			if (j == pat.length) {
				return i;
			}
		}
		return -1;
	};
	int length;
	char *ch;
}