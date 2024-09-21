import numpy as np

def sign(a: float) -> int:
    # sign(0) := -1
    if a <= 0: return -1
    return 1

def read_data(file: str) -> tuple[list, list]:
    X, Y = [], []
    with open(file) as f:
        for line in f:
            data = line.strip('\n').split(' ')
            x = [1]
            for entry in data:
                if '\t' in entry:
                    _data = entry.split('\t')
                    x.append(float(_data[0]))
                    Y.append(int(_data[1]))
                else:
                    x.append(float(entry))
            X.append(x)
    return (X, Y)

def PLA(X: list, Y: list, eta: float = 1.0) -> tuple[np.ndarray, int]:
    """
    Perceptron Learning Algorithm (PLA)
    """
    counter = 0
    # one dummy dimension (4 + 1), for learning the threshold
    w = np.zeros(len(X[0]))
    while True:
        updated = False
        for (x, y) in zip(X, Y):
            if sign(np.dot(w, x)) != y:
                updated = True
                w = w + eta * y * np.array(x)
                counter += 1
                # Note that here we don not `break`!

        if not updated:
            break
    return (w, counter)

def random_PLA(X: list, Y: list, N: int, eta: float) -> int:
    """
    Randomly shuffle the input dataset for PLA

    Parameters:
        ...
        eta: learning rate
    """
    rng = np.random.default_rng()
    total = 0
    for _ in range(N):
        Z = list(zip(X, Y))
        rng.shuffle(Z)
        _X, _Y = zip(*Z)

        _, cnt = PLA(_X, _Y, eta)
        total += cnt
    return total // N

def count_error(X: list, Y: list, w: list) -> int:
    cnt = 0
    for (x, y) in zip(X, Y):
        if sign(np.dot(w, x)) != y:
            cnt += 1
    return cnt

def pocket_alg(X: list, Y: list, T: int) -> int:
    """
    Pocket Algorithm: An approximation for PLA
    """
    rng = np.random.default_rng()
    w = np.zeros(len(X[0]))
    w_pocket = np.zeros(len(X[0]))

    for _ in range(T):
        update = False

        Z = list(zip(X, Y))
        rng.shuffle(Z)
        _X, _Y = zip(*Z)

        for (x, y) in zip(_X, _Y):
            if sign(np.dot(w, x)) != y:
                update = True
                w = w + y * np.array(x)
                break
        if not update:
            break
        
        if count_error(X, Y, w) < count_error(X, Y, w_pocket):
            w_pocket = w.copy()
    return w_pocket

def Q15_16_17():
    X, Y = read_data('./hw1_15_train.dat')
    _, num_iter = PLA(X, Y, 1)

    print(num_iter)
    print(random_PLA(X, Y, 2000, 1))
    print(random_PLA(X, Y, 2000, 0.5))

def Q18(T: int = 50):
    M = 2000
    X_train, Y_train = read_data('./hw1_train.dat')
    X_test, Y_test = read_data('./hw1_test.dat')

    avg_err_rate = 0
    for _ in range(M):
        w = pocket_alg(X_train, Y_train, T)

        err_rate = count_error(X_test, Y_test, w) / len(X_test)
        print('err rate:', err_rate)
        avg_err_rate += err_rate

    avg_err_rate /= M
    print(avg_err_rate)

if __name__ == '__main__':
    Q15_16_17()
    Q18()