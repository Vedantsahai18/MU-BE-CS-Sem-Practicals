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
