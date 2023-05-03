# Written in collaboration with ChatGPT. (2023/03/17)
import math

# Define p, q, and n
p = 10007
q = 10009
n = p * q

# Calculate the totient of n
totient = (p - 1) * (q - 1)

# Find the smallest prime number greater than 2 that is coprime to totient
e = 3
while math.gcd(e, totient) != 1 or not all(e % i for i in range(2, int(math.sqrt(e)) + 1)):
    e += 2

# Find the modular multiplicative inverse of e modulo totient using the extended Euclidean algorithm
def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise ValueError('modular inverse does not exist')
    return x % m

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

d = modinv(e, totient)

# Print the public and private keys
print("Public key (e, n): ({}, {})".format(e, n))
print("Private key (d, n): ({}, {})".format(d, n))

def ascii_to_binary(message):
    binary = ""
    for char in message:
        binary += format(ord(char), '08b')
    return binary

def encrypt(message, e, n):
    # Convert ASCII-coded messages to binary sequence
    binary_message = ''.join(format(ord(c), '08b') for c in message)

    # Group binary sequence by every 26 bits and pad with 0 if necessary
    binary_blocks = [binary_message[i:i+26].ljust(26, '0') for i in range(0, len(binary_message), 26)]

    # Convert each block to an integer and encrypt it
    encrypted_blocks = [pow(int(block, 2), e, n) for block in binary_blocks]

    # Convert integers to binary sequences with 27 bits
    binary_encrypted = ''.join(format(block, '027b') for block in encrypted_blocks)

    # Group binary sequence by every 8 bits and convert to ASCII-coded characters
    binary_blocks = [binary_encrypted[i:i+8] for i in range(0, len(binary_encrypted), 8)]
    if len(binary_blocks[-1]) != 8:
        binary_blocks[-1] = binary_blocks[-1].ljust(8, '0')
    encrypted_message_ascii = ''.join(chr(int(block, 2)) for block in binary_blocks)

    return encrypted_message_ascii


message = "Hello, world!"
encrypted_message = encrypt(message, e, n)

# Convert bytes object to string of ASCII characters
# encrypted_message_ascii = encrypted_message.decode('ascii')

print("encrypted_message:", encrypted_message)

def decrypt(message, d, n):
    # Convert ASCII-coded messages to binary sequence
    binary_message = ''.join(format(ord(c), '08b') for c in message)

    # Group binary sequence by every 27 bits and discard trailing 0
    binary_blocks = [binary_message[i:i+27] for i in range(0, len(binary_message), 27)]
    if len(binary_blocks[-1]) != 27:
        binary_blocks.pop()

    # Convert each block to an integer and decrypt it
    decrypted_blocks = [pow(int(block, 2), d, n) for block in binary_blocks]

    # Convert integers to binary sequences with 26 bits
    binary_decrypted = ''.join(format(block, '026b') for block in decrypted_blocks)

    # Group binary sequence by every 8 bits and convert to ASCII-coded characters
    decrypted_message = ''.join(chr(int(binary_decrypted[i:i+8], 2)) for i in range(0, len(binary_decrypted), 8))

    return decrypted_message

print("decrypted_message:", decrypt(encrypted_message, d, n))
