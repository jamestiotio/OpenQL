# Generated by OpenQL 0.9.0 for program diamond_cqasm
version 1.2

pragma @ql.name("diamond_cqasm")


.__1 @ql.name("")
    x q[0]
    y q[0]
    z q[0]
    h q[0]
    i q[0]
    rx q[0], 3.14
    ry q[0], 3.14
    rz q[0], 3.14
    x90 q[0]
    mx90 q[0]
    y90 q[0]
    my90 q[0]
    s q[0]
    sdag q[0]
    t q[0]
    tdag q[0]
    cnot q[0], q[1]
    cz q[0], q[1]
    swap q[0], q[1]
    cr q[0], q[1], 3.14
    crk q[0], q[1], 0
    toffoli q[0], q[1], q[2]
    measure_z q[0]
    measure_y q[0]
    measure_x q[0]
    { # start at cycle 25
        measure_z q[0]
        measure_z q[1]
        measure_z q[2]
        measure_z q[3]
        measure_z q[4]
        measure_z q[5]
        measure_z q[6]
        measure_z q[7]
        measure_z q[8]
        measure_z q[9]
    }
    skip 37
