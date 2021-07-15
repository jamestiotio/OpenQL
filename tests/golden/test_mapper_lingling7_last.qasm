# Generated by OpenQL 0.9.0 for program test_mapper_lingling7
version 1.2

pragma @ql.name("test_mapper_lingling7")


.kernel_lingling7
    { # start at cycle 0
        prepz q[7]
        prepz q[8]
    }
    skip 30
    y90 q[7]
    { # start at cycle 32
        x q[7]
        ym90 q[5]
    }
    cz q[7], q[5]
    ym90 q[4]
    cz q[7], q[4]
    ym90 q[5]
    cz q[7], q[5]
    skip 1
    { # start at cycle 39
        y90 q[5]
        ym90 q[7]
    }
    cz q[5], q[7]
    skip 1
    { # start at cycle 42
        y90 q[7]
        ym90 q[5]
    }
    cz q[7], q[5]
    skip 1
    { # start at cycle 45
        y90 q[5]
        ym90 q[8]
    }
    cz q[5], q[8]
    skip 1
    cz q[5], q[8]
    skip 1
    ym90 q[8]
    cz q[5], q[8]
    skip 1
    { # start at cycle 53
        y90 q[8]
        ym90 q[5]
    }
    cz q[8], q[5]
    skip 1
    { # start at cycle 56
        y90 q[5]
        ym90 q[8]
    }
    cz q[5], q[8]
    skip 1
    cz q[2], q[5]
    skip 1
    { # start at cycle 61
        y90 q[8]
        ym90 q[6]
    }
    cz q[8], q[6]
    skip 1
    { # start at cycle 64
        y90 q[6]
        ym90 q[8]
    }
    cz q[6], q[8]
    skip 1
    { # start at cycle 67
        y90 q[8]
        ym90 q[6]
    }
    cz q[8], q[6]
    skip 1
    { # start at cycle 70
        y90 q[6]
        ym90 q[8]
    }
    { # start at cycle 71
        cz q[6], q[8]
        ym90 q[2]
    }
    cz q[5], q[2]
    y90 q[8]
    cz q[8], q[5]
    skip 1
    { # start at cycle 76
        y90 q[2]
        ym90 q[5]
    }
    cz q[2], q[5]
    skip 1
    { # start at cycle 79
        y90 q[5]
        ym90 q[2]
    }
    cz q[5], q[2]
    skip 1
    y90 q[2]
    cz q[0], q[2]
    skip 1
    ym90 q[5]
    cz q[2], q[5]
    skip 1
    { # start at cycle 88
        y90 q[5]
        ym90 q[2]
    }
    cz q[5], q[2]
    cz q[7], q[4]
    { # start at cycle 91
        y90 q[2]
        ym90 q[5]
    }
    { # start at cycle 92
        y90 q[4]
        ym90 q[7]
        cz q[2], q[5]
    }
    { # start at cycle 93
        ym90 q[3]
        cz q[4], q[7]
    }
    cz q[6], q[3]
    { # start at cycle 95
        y90 q[7]
        y90 q[5]
    }
    { # start at cycle 96
        y90 q[6]
        cz q[7], q[5]
    }
    x q[6]
    y90 q[5]
    { # start at cycle 99
        measure q[6]
        measure q[5]
    }
    skip 14
    { # start at cycle 114
        prepz q[6]
        prepz q[5]
    }
    skip 30
    y90 q[6]
    { # start at cycle 146
        x q[6]
        ym90 q[8]
    }
    cz q[6], q[8]
    skip 1
    cz q[6], q[3]
    skip 1
    ym90 q[6]
    cz q[2], q[6]
    skip 1
    ym90 q[5]
    cz q[2], q[5]
    skip 1
    { # start at cycle 157
        y90 q[6]
        ym90 q[2]
    }
    cz q[6], q[2]
    skip 1
    { # start at cycle 160
        y90 q[8]
        y90 q[2]
        ym90 q[6]
    }
    { # start at cycle 161
        cz q[8], q[5]
        cz q[2], q[6]
    }
    ym90 q[4]
    cz q[1], q[5]
    { # start at cycle 164
        cz q[7], q[4]
        ym90 q[2]
    }
    cz q[5], q[2]
    ym90 q[7]
    { # start at cycle 167
        y90 q[2]
        ym90 q[5]
        cz q[7], q[4]
    }
    cz q[2], q[5]
    { # start at cycle 169
        y90 q[4]
        ym90 q[7]
    }
    { # start at cycle 170
        y90 q[5]
        ym90 q[2]
        cz q[4], q[7]
    }
    cz q[5], q[2]
    y90 q[7]
    cz q[5], q[7]
    skip 1
    cz q[5], q[7]
    y90 q[2]
    cz q[5], q[2]
    ym90 q[4]
    { # start at cycle 179
        cz q[7], q[4]
        cz q[5], q[2]
    }
    skip 1
    { # start at cycle 181
        y90 q[7]
        ym90 q[5]
    }
    cz q[7], q[5]
    skip 1
    { # start at cycle 184
        y90 q[5]
        ym90 q[7]
    }
    cz q[5], q[7]
    skip 1
    { # start at cycle 187
        y90 q[7]
        y90 q[4]
    }
    cz q[7], q[4]
    skip 1
    y90 q[7]
    x q[7]
    measure q[7]
    skip 8
    cz q[5], q[2]
    skip 1
    y90 q[2]
    measure q[2]
    skip 2
    prepz q[7]
    skip 11
    prepz q[2]
    skip 18
    y90 q[7]
    { # start at cycle 239
        x q[7]
        ym90 q[5]
    }
    cz q[7], q[5]
    skip 1
    { # start at cycle 242
        y90 q[5]
        ym90 q[8]
    }
    cz q[5], q[8]
    skip 1
    { # start at cycle 245
        y90 q[8]
        ym90 q[5]
    }
    cz q[8], q[5]
    skip 1
    { # start at cycle 248
        y90 q[5]
        ym90 q[8]
    }
    cz q[5], q[8]
    ym90 q[2]
    cz q[5], q[2]
    skip 1
    ym90 q[5]
    cz q[7], q[5]
    skip 1
    { # start at cycle 256
        y90 q[6]
        y90 q[5]
        ym90 q[7]
    }
    { # start at cycle 257
        cz q[6], q[2]
        cz q[5], q[7]
    }
    skip 1
    { # start at cycle 259
        y90 q[7]
        ym90 q[5]
    }
    { # start at cycle 260
        cz q[0], q[2]
        cz q[7], q[5]
    }
    skip 1
    y90 q[5]
    cz q[5], q[2]
    skip 1
    cz q[5], q[2]
    ym90 q[1]
    cz q[5], q[1]
    ym90 q[2]
    cz q[5], q[2]
    { # start at cycle 270
        ym90 q[7]
        y90 q[1]
    }
    { # start at cycle 271
        cz q[5], q[7]
        cz q[1], q[4]
    }
    skip 1
    { # start at cycle 273
        y90 q[2]
        ym90 q[5]
    }
    cz q[2], q[5]
    skip 1
    { # start at cycle 276
        y90 q[5]
        ym90 q[2]
    }
    cz q[5], q[2]
    { # start at cycle 278
        y90 q[4]
        ym90 q[1]
    }
    { # start at cycle 279
        y90 q[2]
        ym90 q[6]
        cz q[4], q[1]
    }
    cz q[2], q[6]
    y90 q[1]
    cz q[1], q[5]
    y90 q[2]
    { # start at cycle 284
        x q[2]
        y90 q[5]
    }
    { # start at cycle 285
        measure q[2]
        measure q[5]
    }
    skip 10
    ym90 q[4]
    cz q[1], q[4]
    skip 1
    { # start at cycle 299
        y90 q[3]
        y90 q[4]
        y90 q[6]
        y90 q[7]
        y90 q[8]
    }
