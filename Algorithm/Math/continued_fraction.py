import numpy as np

"""
Let r_0 = r. Let [a_i] be the continued fraction of r (possibly truncated).
Then
    r_0 = a_0 + 1/r_1
    r_1 = a_1 + 1/r_2
    r_2 = a_2 + 1/r_3
    ... 
"""
def continued_fraction(r: float, output_len: int) -> list[int]:
    seq = []
    for _ in range(output_len):
        seq.append(int(r // 1))
        r -= r // 1
        r = 1 / r
    return seq


if __name__ == '__main__':
    print(continued_fraction(np.pi, 10))
    print(continued_fraction(np.e, 10))