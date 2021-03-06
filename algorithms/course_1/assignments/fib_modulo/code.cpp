#include <iostream>

using namespace std;

#define MODULO 1000000007

///
///
///
/// BEST IMPLEMENTATION IN LOG N time
///
///
///

void multMatrix(vector<vector<long long> > &m, vector<vector<long long> > &n){
    long long a = (m[0][0] * n[0][0] +  m[0][1] * n[1][0]) % MODULO;
    long long b = (m[0][0] * n[0][1] +  m[0][1] * n[1][1]) % MODULO;
    long long c = (m[1][0] * n[0][0] +  m[1][1] * n[0][1]) % MODULO;
    long long d = (m[1][0] * n[0][1] +  m[1][1] * n[1][1]) % MODULO;

    m[0][0] = a;
    m[0][1] = b;
    m[1][0] = c;
    m[1][1] = d;
}

long long getNthFib(long long n){
	if (n <= 1) return n;
	vector<vector<long long> > result {{1,0},{0,1}};
	vector<vector<long long> > fiboM {{1,1}, {1,0}};
	while(n > 0){
	    if (n%2 == 1) {
	        multMatrix(result, fiboM);
	    }
	    n = n / 2;
	    multMatrix(fiboM, fiboM);
	}
	return (result[1][0] % MODULO);
}

//////
///
///
///
///
///
///
int fib(long long n, int m){
	int cur = 0;
	int next = 1;
	int tmp;
	for(int i = 0; i < n; i++){
		tmp = next + cur;
		cur = next % m;
		next = tmp % m;
	}
	return cur;
}


long long find_fib_period(int m){
	if (m == 1){
		return 0;
	}
	long long n = m*m+2;
	int cur = 0;
	int next = 1;
	long long tmp, answer = n;
	for(long long i = 0; i < n; i++){
		if (cur == 0 && next == 1 && i > 0){
			answer = i;
			break;
		}
		tmp = cur + next;
		cur = next % m;
		next = tmp % m;
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	long long n;
	int m;

	cin >> n >> m;

	int answer = find_fib_period(m);
	if (answer == 0){
		cout << 0 << endl;
	}
	else{
		long long index = n % answer;
		cout << fib(index, m);
	}
	return 0;
}