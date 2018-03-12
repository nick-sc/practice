#include <iostream>

using namespace std;

int tc, n_doc, loc_doc;

int find_weights(int *arr, int f, int r)
{
	int w = 0;

	for (int i = f; i < r; i++)
	{
		if (w < arr[i])
			w = arr[i];
	}

	return w;
}


int main()
{
	cin >> tc;

	while (tc--)
	{
		int doc_q[5055] = { 0 };
		int q_f = 0;
		int q_r = 0;
		int weights = 0;
		int cnt = 0;

		cin >> n_doc >> loc_doc;

		for (int i = 0; i < n_doc; i++)
			cin >> doc_q[i];

		q_r = n_doc;
		weights = find_weights(doc_q, q_f, q_r);

		while (q_f < q_r)
		{
			

			if (doc_q[q_f] >= weights)	//�߿��Ҷ�
			{
				cnt++;					//�μ��� ������ ���� ī��Ʈ

				if (q_f == loc_doc)		//Ÿ�� ������ �μ����� ���
				{
					cout << cnt << "\n";
					break;
				}

				q_f++;
				weights = find_weights(doc_q, q_f, q_r);
			}
			else                        //���߿��Ҷ�
			{
				if (q_f == loc_doc)		//Ÿ�� ������ ��ġ�� ����Ǿ��� ��
					loc_doc = q_r;

				doc_q[q_r++] = doc_q[q_f++];
			}
		}

	}

	return 0;
}