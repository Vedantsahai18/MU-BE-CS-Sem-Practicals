import hashlib, os


def hash_pwd(password):
    # Hash, salt to be stored in DB

    salt = hashlib.sha256(os.urandom(60)).hexdigest().encode("ascii")
    pepper = b"M"
    password = password.encode("utf-8")

    pwdhash = hashlib.sha512(password + salt + pepper).hexdigest()

    """ 
    os.urandom(size) :
    Size: It is the size of string random bytes
    Return Value: This method returns a string which represents random bytes suitable for cryptographic use.

    encode() : 
    Converts the string into bytes to be acceptable by hash function.
    
    hexdigest() : 
    Returns the encoded data in hexadecimal format.
    """
    print(
        "--------------Hashing Algo-----------------\nsalt: {}".format(
            salt.decode("ascii")
        )
    )
    print("pepper: {}".format(pepper.decode("ascii")))
    print("password: {}".format(password.decode("utf-8")))
    print("pwdhash: {}\n------------------------------------------".format(pwdhash))

    return salt.decode("ascii") + pwdhash


def verify_pwd(salt, stored_password, provided_password):
    pepper = b"M"

    pwd_hash = hashlib.sha512(
        provided_password.encode("utf-8") + salt.encode("ascii") + pepper
    ).hexdigest()
    print(
        "--------------Verifying Hash---------------\nstored_password : {}\nprovided_password : {}\n------------------------------------------".format(
            stored_password, provided_password
        )
    )
    return pwd_hash == stored_password


if __name__ == "__main__":
    while True:

        choice = int(
            input(
                "_____________Salt & Pepper________________\n1. Register\n2.Login\nEnter : "
            )
        )
        if choice == 1:
            user_name = str(input("Enter Username : "))
            password = str(input("Enter Password : "))
            stored_pwd = hash_pwd(password)
            salt = stored_pwd[:64]
            stored_pwd = stored_pwd[64:]
            with open("DB.csv", "a+") as db:
                db.write("{},{},{}\n".format(user_name, salt, stored_pwd))
            continue

        elif choice == 2:
            user_name = str(input("Enter Username : "))
            password = str(input("Enter Password : "))
            with open("DB.csv", "r") as db:
                for line in db:
                    check = False
                    if user_name in line:
                        found_user_details = line
                        check = True
                        break
            if check:
                print("User Exists")
                found_user, found_salt, found_hash = map(
                    str, found_user_details.split(",")
                )
                if verify_pwd(found_salt, found_hash.rstrip(), password):
                    print("Valid User!")
                else:
                    print("Error incorrect password!")
            else:
                print("User Doesn't Exists")

        else:
            print("_____________Goodbye_____________")
            break
# Output :
#
# PS C:\Users\Darlene\Desktop\Sem 6\CSS> python salt-pepper.py
# _____________Salt & Pepper________________
# 1. Register
# 2.Login
# Enter : 1
# Enter Username : Bob
# Enter Password : 99Pancakes
# --------------Hashing Algo-----------------
# salt: c1c5b3bc1829fe955e327072dfa1c3d66bb11801a5bbef7f7a2e161101310977
# pepper: M
# password: 99Pancakes
# pwdhash: fa7e6aa5738074b43e5c584fb2ccb1a0151f892066503191b7a46dc5d4a87c3b4e909dade60464ce95188d73d3afb271142ffabba116927023166c424b4c1243
# ------------------------------------------
# _____________Salt & Pepper________________
# 1. Register
# 2.Login
# Enter : 2
# Enter Username : Bob
# Enter Password : 99pancakes
# User Exists
# --------------Verifying Hash---------------
# stored_password : fa7e6aa5738074b43e5c584fb2ccb1a0151f892066503191b7a46dc5d4a87c3b4e909dade60464ce95188d73d3afb271142ffabba116927023166c424b4c1243
# provided_password : 99pancakes
# ------------------------------------------
# Error incorrect password!
# _____________Salt & Pepper________________
# 1. Register
# 2.Login
# Enter : 2
# Enter Username : Bob
# Enter Password : 99Pancakes
# User Exists
# --------------Verifying Hash---------------
# stored_password : fa7e6aa5738074b43e5c584fb2ccb1a0151f892066503191b7a46dc5d4a87c3b4e909dade60464ce95188d73d3afb271142ffabba116927023166c424b4c1243
# provided_password : 99Pancakes
# ------------------------------------------
# Valid User!
# _____________Salt & Pepper________________
# 1. Register
# 2.Login
# Enter : 3
# __________________Goodbye_________________
