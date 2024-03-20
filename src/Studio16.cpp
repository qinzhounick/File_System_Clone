#include "../include/mockos/TextFile.h"

using namespace std;

int main() {
    TextFile tf = TextFile("What is happening?");
    //cout << tf.getName();
    vector<char> vc1 = { 'U', 'F', 'A', 'I', 'L' };
    vector<char> vc2 = { 'N', 'O' };
    tf.write(vc1);
    //tf.getSize();
    //tf.append(vc2);
    //tf.getSize();
    tf.read();

    AbstractFile& af = tf;
    af.write(vc1);
    af.read();
    return 0;
}