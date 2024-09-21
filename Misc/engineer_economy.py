import matplotlib.pyplot as plt
import numpy as np

def P_from_G(i, N):
    i_1_N = (1 + i)**N
    return 1 / i * ((i_1_N - 1) / (i * i_1_N) - N / i_1_N)

def P_from_A(i, N):
    i_1_N = (1 + i)**N
    return (i_1_N - 1) / (i * i_1_N)

def A_from_P(i, N):
    i_1_N = (1 + i)**N
    return 1 / (i_1_N - 1) * (i * i_1_N)

def A_from_F(i, N):
    return A_from_P(i, N) * P_from_F(i, N)

def F_from_A(i, N):
    i_1_N = (1 + i)**N
    return (i_1_N - 1) / i

def sum_i_1(i, N):
    return ((1 + i)**N - 1) / i

def F_from_P(i, N):
    return (1 + i)**N

def P_from_F(i, N):
    return (1 + i)**(-N)

def P_from_two_rates(f, i, N):
    if i == f:
        return N * P_from_F(i, 1)
    return (1 - P_from_F(i, N) * F_from_P(f, N)) / (i - f)

# Present Worth
def PW(cash_flow: list[int], i: float) -> float:
    return sum([cash * P_from_F(i, k) for k, cash in enumerate(cash_flow)])


# Future Worth
def FW(cash_flow: list[int], i: float) -> float:
    return sum([cash * F_from_P(i, k) for k, cash in enumerate(cash_flow)])


def AW(
        initial_investment: float, 
        annual_revenues: float, 
        annual_cost: float,
        salvage_value:float,
        i: float,
        N: int
) -> float:
    return -initial_investment * A_from_P(i, N) + (annual_revenues - annual_cost) + salvage_value * A_from_F(i, N)


def ERR(LHS_partial: float, RHS: float, N: int):
    return (RHS / LHS_partial) ** (1 / N) - 1


def IRR(
        initial_investment: float, 
        annual_revenues: float, 
        annual_cost: float,
        salvage_value:float,
        N: int
) -> float:
    prev = 0
    for i in np.linspace(0.001, 1, 1000):
        aw = AW(initial_investment, annual_revenues, annual_cost, salvage_value, i, N)
        if aw <= 0 and prev > 0:
            return i
        prev = aw
    return -1

def prob1():
    offset = 10**5
    cash_flow = np.array([0, 5, 3, 1, -24, 1.5, 2, 2.5, 3, 3.5, 4])
    IRRs = np.linspace(0, 1, 1000)
    # for i in [0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4]:
        # PW = sum([cash * P_from_F(i, k + 1) for k, cash in enumerate(cash_flow)])
        # print(PW)
    PWs = [PW(cash_flow, i) for i in IRRs]

    
    EPS = 10**-2
    for i in IRRs:
        pw = PW(cash_flow, i)
        if abs(pw) < EPS:
            print(f'IRR: {i}, PW: {pw}')
    # plt.plot(IRRs, PWs)
    # plt.show()
    print(PW(cash_flow, 0.04), PW(cash_flow, 0.05))
    print(PW(cash_flow, 0.31), PW(cash_flow, 0.32))


def prob1a():
    N = 10
    ext_rate = 0.08
    Rs = np.array([0, 5, 3, 1, 0, 1.5, 2, 2.5, 3, 3.5, 4])
    RHS = sum([Rk * F_from_P(ext_rate, N - k) for k, Rk in enumerate(Rs)])
    LHS_partial = 24 * P_from_F(ext_rate, 4)
    print(LHS_partial, RHS)
    print(f'ERR: {ERR(LHS_partial, RHS, N)}')


def prob3():
    cash_flow = [-100000, 20000, 30000, 40000, 50000, 70000]
    print(f'PW(0.2) = {PW(cash_flow, 0.20)}')
    print(f'PW(0.25) = {PW(cash_flow, 0.25)}')
    IRR = 5 / (-902.4-12892.2) * (-12892.2) + 20
    print(f'IRR = {IRR}')


def prob4():
    cash_flow = [0, -35, 55, 175, 250]
    print(PW(cash_flow, 0.08))


def prob5():
    i = 0.1
    N = 8
    pw1 = -600 - 780 * P_from_A(i, N)
    pw2 = -760 - 728 * P_from_A(i, N)
    pw3 = -1240 - 630 * P_from_A(i, N)
    pw4 = -1600 - 574 * P_from_A(i, N)
    print(pw1, pw2, pw3, pw4)
    
    print('---------------------')

    C = [-600, -760, -1240, -1600]
    A = [-780, -728, -630, -574]

    print([C[k] * F_from_P(i, N) + A[k] * F_from_A(i, N) for k in range(4)])
    print('---------------------')
    print([C[k] * A_from_P(i, N) + A[k] for k in range(4)])


def prob6():
    i = 0.08
    f = 0.05
    N = 20
    pw1 = -225 - 2 * P_from_A(i, N) - 5 * P_from_two_rates(f, i, N)
    print(pw1)

    pw2 = -200 - 10 * P_from_A(i, N)
    print(pw2)


def prob7():
    N = 15
    # for i in [0.15, 0.18]:
    #     aw1 = -300 * A_from_P(i, N) + 70 - 13 + 35 * A_from_F(i, N)
    #     print(aw1)
    # a = 0.03/(-1.3467-6.4304) * (-6.4304) + 0.15
    # # print(a)

    # for i in [0.12, 0.11]:
    #     aw2 = -100 * A_from_P(i, N) + 0 - (-5) + 5 * A_from_F(i, N)
    #     print(aw2)

    # for i in [0.04, 0.12]:
    #     aw3 = -150 * A_from_P(i, N) + 10 - (-3) + 15 * A_from_F(i, N)
    #     print(aw3)
    I = [450, 400, 300]
    AR = [80, 70, 70]
    AC = [10, 8, 13]
    SAL = [50, 40, 35]
    N = 15
    for k in range(3):
        print(f'IRR = {IRR(I[k], AR[k], AC[k], SAL[k], N)}')

    print(IRR(I[0] - I[2], AR[0] - AR[2], AC[0] - AC[2], SAL[0] - SAL[2], N))


def prob8():
    init_ex = [13000, 13550, 14000]
    ann_ex = [4781, 5281, 6081]
    ann_r = [6781, 7581, 7581]
    salvage = [1300, 1600, 2000]

    i = 0.08
    N = 10
    for j in range(3):
        aw = -init_ex[j] * A_from_P(i, N) - ann_ex[j] + ann_r[j] + salvage[j] * A_from_F(i, N)
        print(aw)


if __name__ == '__main__':
    prob8()