#include "../include/instances.hpp"
using namespace std;
using namespace fly;

ApplicationLayer AppLayerInstance;
PresentationLayer PreLayerInstance;
TransferLayer TransLayerInstance;

void output(queue<vector<uint8_t>> &test)
{
        while (!test.empty())
        {
                vector<uint8_t> test_vec = test.front();
                vector<uint8_t>::iterator it;
                for (it = test_vec.begin(); it != test_vec.end(); it++)
                {
                        cout << (unsigned)*it << "*";
                }
                cout << endl;
                test.pop();
        }
}

int main()
{
        // init log
        Log::get().setLogStream(cout);
        Log::get().setLevel(Debug);

        int listener = TransLayerInstance.get_listener(20343);
        TransLayerInstance.select_loop(listener);

        return 0;
}
