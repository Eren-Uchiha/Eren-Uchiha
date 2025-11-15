import secrets
import string
AMBIGUOUS = {'l','I','1','O','0'}

def generate_password(length=16, use_lower=True, use_upper=True, use_digits=True, use_symbols=True, exclude_ambiguous=False):
    if length < 1:
        raise ValueError("length must be >= 1")
    pools = []
    if use_lower:
        pools.append(string.ascii_lowercase)
    if use_upper:
        pools.append(string.ascii_uppercase)
    if use_digits:
        pools.append(string.digits)
    if use_symbols:
        pools.append("!@#$%^&*()-_=+[]{};:,.<>?")
    if not pools:
        raise ValueError("At least one character type must be enabled")

    charset = "".join(pools)
    if exclude_ambiguous:
        charset = "".join(ch for ch in charset if ch not in AMBIGUOUS)
        if not charset:
            raise ValueError("ALL character were excluded as ambiguous")
    password_chars = []
    for pool in pools:
        pool_filtered = pool
        if exclude_ambiguous:
            pool_filtered = "".join(ch for ch in pool if ch not in AMBIGUOUS)  
            if not pool_filtered:
                continue
        password_chars.append(secrets.choice(pool_filtered))
    while len(password_chars) < length :
        password_chars.append(secrets.choice(charset))

    secrets.SystemRandom().shuffle(password_chars)
    return "".join(password_chars)

if __name__ == "__main__":
    print(generate_password(16))    