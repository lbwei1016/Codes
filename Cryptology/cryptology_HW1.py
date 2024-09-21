import numpy as np
from scipy.stats import entropy

base = 2  # work in units of bits
# M = np.array([0.45, 0.3, 0.25])
# K = np.array([0.2, 0.15, 0.25, 0.4])
# C = np.array([0.345, 0.2275, 0.2075, 0.22])
# EM = entropy(M, base=base)
# EK = entropy(K, base=base)
# EC = entropy(C, base=base)
# EKC = EM + EK
# # print(EM, EK, EC)
# # print(EM + EK)

MC = np.array([0.27, 0.0675, 0.1125, 0.075, 0.06, 0.045, 0.12, 0.1, 0.05, 0.1])
EMC = entropy(MC, base=base)
print(EMC)
# print(EMC-EC)
# print(EMC-EM)
# print(EKC-EC)

# U = np.array([0.5, 0.5])
# EU = entropy(U, base=base)
# print(0.27*EU+0.1*EU)

# M = np.array([np.ceil(np.abs(m - 12.5))/182 for m in range(26)])
# EM = entropy(M, base=base)
# print(EM)
# K = np.array([1/26 for i in range(26)])
# EK = entropy(K, base=base)
# print(EK)

def prob_m(m):
    return np.ceil(np.abs(m - 12.5))/182

S = 26
# CC = np.array([[0 for _ in range(S)] for _ in range(S)], dtype=float)
# for c1 in range(S):
#     for c2 in range(S):
#         for k in range(S):
#             # print(prob_m((c1 - k + S) % S))
#             # print((c1 - k + S) % S)
#             # print(CC[c1][c2])
#             # print(prob_m((c1 - k + S) % S) * prob_m((c2 - k + S) % S))
#             CC[c1][c2] += prob_m((c1 - k + S) % S) * prob_m((c2 - k + S) % S)
# CC /= S
# # print(np.sum(CC))

# HCC = 0
# for c1 in range(S):
#     for c2 in range(S):
#         if CC[c1][c2] == 0: continue
#         HCC += CC[c1][c2] * np.log2(1 / CC[c1][c2])
# print(HCC)

# accum = 0
# HMMCC = 0
# for m1 in range(S):
#     for m2 in range(S):
#         for k in range(S):
#             prob = prob_m(m1) * prob_m(m2) / S
#             accum += prob
#             if prob == 0: continue
#             HMMCC += prob * np.log2(1 / prob)
# print(accum)
# print(HMMCC)

accum = 0
HMM = 0
for m1 in range(S):
    for m2 in range(S):
        prob = prob_m(m1) * prob_m(m2)
        accum += prob
        if prob == 0: continue
        HMM += prob * np.log2(1 / prob)
print(accum)
print(HMM)