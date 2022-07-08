#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "rlp.hpp"
#include "getTransactionHash.hpp"

using namespace std;

void testGetTransactionHash(void)
{
    Context_ ctx;
    string to, data, res, expected;
    stringstream hex;
    bool isOk;

    ctx.v = 27;
    ctx.r.set_str("1186622d03b6b8da7cf111d1ccba5bb185c56deae6a322cebc6dda0556f3cb97", 16);
    ctx.s.set_str("00910c26408b64b51c5da36ba2f38ef55ba1cee719d5a6c01225968799907432", 16);

    to = "0x4d5Cf5032B2a844602278b01199ED191A86c93ff";
    data = "0x";
    res = getTransactionHash(ctx, to, 0x016345785d8a0000, 0, 0x0186a0, 0x3b9aca00, data, 1001);

    expected = "0x0cc3dd49b941271b19df83ba6733bed4023fb82c28d40e6ef863ca589d4a933a";
    isOk = (strcasecmp(res.c_str(), expected.c_str()) == 0);
    cout << "TEST1 " << ( isOk ? "OK" : "FAIL") << endl;
    cout << "res: " << res << endl;
    if (!isOk) {
        cout << "exp: " << expected << endl;
    }
    cout << endl;

    ctx.v = 27;
    ctx.r.set_str("1186622d03b6b8da7cf111d1ccba5bb185c56deae6a322cebc6dda0556f3cb97", 16);
    ctx.s.set_str("00910c26408b64b51c5da36ba2f38ef55ba1cee719d5a6c01225968799907432", 16);

    to = "0x4d5Cf5032B2a844602278b01199ED191A86c93ff";
    data = "0x";
    res = getTransactionHash(ctx, to, 0x016345785d8a0000, 0, 0x0186a0, 0x3b9aca00, data, 1001);

    expected = "0x0cc3dd49b941271b19df83ba6733bed4023fb82c28d40e6ef863ca589d4a933a";
    isOk = (strcasecmp(res.c_str(), expected.c_str()) == 0);
    cout << "TEST2 " << ( isOk ? "OK" : "FAIL") << endl;
    cout << "res: " << res << endl;
    if (!isOk) {
        cout << "exp: " << expected << endl;
    }
    cout << endl;

    ctx.v = 27;
    ctx.r.set_str("b22577e12dd4e9c8c7c9f68a63d6ab3ec6fb612ee6b206dbcd7817257d816e75", 16);
    ctx.s.set_str("2e69f816289c68eab050ddc279714bd05dc567ec3fc883148a0338334f3d5e77", 16);

    to = "0x1275fbb540c8efC58b812ba83B0D0B8b9917AE98";
    data = "0x15927819";
    res = getTransactionHash(ctx, to, 0, 0, 0x0186a0, 0x3b9aca00, data, 1001);

    expected = "0xe73241ad9d642066483b1c85439d1f3fe77f854b2c61292e31c185bdefe21308";
    isOk = (strcasecmp(res.c_str(), expected.c_str()) == 0);
    cout << "TEST3 " << ( isOk ? "OK" : "FAIL") << endl;
    cout << "res: " << res << endl;
    if (!isOk) {
        cout << "exp: " << expected << endl;
    }
    cout << endl;

    ctx.v = 0x25;
    ctx.r.set_str("044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d", 16);
    ctx.s.set_str("044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d", 16);

    to = "0x3535353535353535353535353535353535353535";
    data = "";
    res = getTransactionHash(ctx, to, 0, 0, 0x5208, 0x04a817c800, data, 1);

    expected = "0xb1e2188bc490908a78184e4818dca53684167507417fdb4c09c2d64d32a9896a";
    isOk = (strcasecmp(res.c_str(), expected.c_str()) == 0);
    cout << "TEST4 " << ( isOk ? "OK" : "FAIL") << endl;
    cout << "res: " << res << endl;
    if (!isOk) {
        cout << "exp: " << expected << endl;
    }
    cout << endl;

    ctx.v = 0x25;
    ctx.r.set_str("64b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c12", 16);
    ctx.s.set_str("64b1702d9298fee62dfeccc57d322a463ad55ca201256d01f62b45b2e1c21c10", 16);

    to = "0x3535353535353535353535353535353535353535";
    data = "";
    res = getTransactionHash(ctx, to, 0x0200, 0x08, 0x02e248, 0x04a817c808, data, 1);

    expected = "0x588df025c4c2d757d3e314bd3dfbfe352687324e6b8557ad1731585e96928aed";
    isOk = (strcasecmp(res.c_str(), expected.c_str()) == 0);
    cout << "TEST5 " << ( isOk ? "OK" : "FAIL") << endl;
    cout << "res: " << res << endl;
    if (!isOk) {
        cout << "exp: " << expected << endl;
    }
    cout << endl;
}