N = [n for n in range(8, 128)]
M = [m for m in range(1, 17)]
P = [p for p in range(2, 32)]
Q = [2*q for q in range(1, 5)]
R = [2*q for q in range(1, 5)]

sysclk_limit_MHz = 170
HSI16_MHz = 16
HSE24_MHz = 24
mega = 10**6

def compute_mnd(divisors, input_MHz, output_limit_MHz):
    omnd = []
    input = input_MHz * mega
    output_limit = output_limit_MHz * mega

    for d in divisors:
        for m in M:
            for n in N:
                num = input * n
                denom = m * d
                if ((num % denom) == 0):
                    output = int(num / denom)
                    if (output <= output_limit):
                        if not any(x[0] == output for x in omnd):
                            omnd.append([output, m, n, d])
   
    omnd.sort(key=lambda x: x[0])
    return omnd

def speed_match_PQR(input_MHz):
    pmnp = compute_mnd(P, input_MHz, sysclk_limit_MHz)
    qmnq = compute_mnd(Q, input_MHz, sysclk_limit_MHz)
    rmnr = compute_mnd(R, input_MHz, sysclk_limit_MHz)

    speed_match_indices = [
            (i, j, k)
            for i, x in enumerate(pmnp)
            for j, y in enumerate(qmnq)
            for k, z in enumerate(rmnr)
            if (x[0] == y[0] == z[0]) and (x[1] == y[1] == z[1]) and (x[2] == y[2] == z[2])
            ]

    # speed matched outputs.
    pmnp = [pmnp[i] for i, j, k in speed_match_indices]
    qmnq = [qmnq[j] for i, j, k in speed_match_indices]
    rmnr = [rmnr[k] for i, j, k in speed_match_indices]

    return pmnp, qmnq, rmnr

def to_file(pmnp, qmnq, rmnr, input_MHz, directive_prefix, filename):
    header = filename.upper().replace(".", "_")
    with open(filename, "w") as f:
        f.write(f"#ifndef {header}\n")
        f.write(f"#define {header}\n\n")
        for p, q, r in zip(pmnp, qmnq, rmnr):
            f.write(f"/* Output on P, Q and R channels: {p[0]/mega:8.4f} MHz. Input: {input_MHz} MHz */\n")
            f.write(f"#define {directive_prefix}_PLLM_{p[0]:09d}      0x{p[1]-1:X}U\n")
            f.write(f"#define {directive_prefix}_PLLN_{p[0]:09d}      0x{p[2]:X}U\n")
            f.write(f"#define {directive_prefix}_PLLPDIV_{p[0]:09d}   0x{p[3]:X}U\n")
            f.write(f"#define {directive_prefix}_PLLQ_{p[0]:09d}      0x{q[3]//2-1:X}U\n")
            f.write(f"#define {directive_prefix}_PLLR_{p[0]:09d}      0x{r[3]//2-1:X}U\n\n")
        f.write("#endif")

def make_speed_matched_headers(input_MHz, filename, directive_prefix):
    pmnp, qmnq, rmnr = speed_match_PQR(input_MHz)
    to_file(pmnp, qmnq, rmnr, input_MHz, directive_prefix, filename)

make_speed_matched_headers(HSI16_MHz, "pll_hsi16_match.h", "HSI16_MATCH")
make_speed_matched_headers(HSE24_MHz, "pll_hse24_match.h", "HSE24_MATCH")
