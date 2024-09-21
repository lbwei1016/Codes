from pwn import *

def check_imap(ip: str, user: str, passwd: str) -> tuple[bool, remote]:
    conn = remote(ip, '465', ssl=True)
    res = conn.recvline()
    print(res.decode())
    
    conn.send(b'ehlo cs.nycu.edu.tw\r\n')
    res = conn.recvuntil(b'250 CHUNKING\r\n', drop=True)
    print(res.decode())

    conn.send(b'auth login\r\n')
    res = conn.recvline()
    print(res.decode())

    user_b64 = str(b64e(user.encode('utf-8')) + '\r\n')
    conn.send(user_b64.encode('utf-8'))
    res = conn.recvline()
    print(res.decode())

    passwd_b64 = str(b64e(passwd.encode('utf-8')) + '\r\n')
    conn.send(passwd_b64.encode('utf-8'))
    res = conn.recvline()
    print(res.decode())

    # conn.close()

    if res == b'235 2.7.0 Authentication successful\r\n':
        return (True, conn)
    else: 
        return (False, conn)
    

def send_mail(conn: remote, user: str, from_host: str) -> bool:
    conn.send(f'mail from: <{user}@cs.nycu.edu.tw>\r\n'.encode('utf-8'))
    res = conn.recvline()
    print(res.decode())
    conn.send(f'rcpt to: <{user}@cs.nycu.edu.tw>\r\n'.encode('utf-8'))
    res = conn.recvline()
    print(res.decode())
    conn.send(b'data\r\n')
    res = conn.recvline()
    print(res.decode())
    conn.send(f'Subject: TEST for csmail-docker (from {from_host})\r\n'.encode())
    conn.send(b'TEST\r\n')
    conn.send(b'.\r\n')
    res = conn.recvline()
    print(res.decode())

    conn.close()

    if '250 2.0.0 Ok' in res.decode('utf-8'):
        return True
    else:
        return False


if __name__ == '__main__':
    # csmail_docker_ip = '10.2.0.46'
    csmail_docker_ip = 'csmail7'
    user = input('Please input the username (who to send a mail): ').strip('\n')
    passwd = input('Please input the password: ').strip('\n')
    print('Now try to login...')

    res, conn = check_imap(csmail_docker_ip, user, passwd)
    if res == True:
        print('SMTP login successfully!')
        print('Now try to send a mail...')
        res = send_mail(conn, user, csmail_docker_ip)
        if res == True:
            print('Mail is sent successfully!')
        else:
            print('Mail not sent!')
    else:
        print('SMTP login failed!')
        conn.close()