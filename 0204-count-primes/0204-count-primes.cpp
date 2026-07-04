class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> isComposite(n);

        for (int i = 2; i < n; i++) {
            if (!isComposite[i])
                primes.push_back(i);

            for (int p : primes) {
                if (i * p >= n)
                    break;

                isComposite[i * p] = true;

                if (i % p == 0)
                    break;
            }
        }
        return primes.size();
    }
};