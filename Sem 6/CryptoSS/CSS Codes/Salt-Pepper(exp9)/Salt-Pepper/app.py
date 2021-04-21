from flask import Flask, request, url_for, redirect, render_template, flash
import forms as form

app = Flask(__name__)
app.config["SECRET_KEY"] = "5791628bb0b13ce0c676dfde280ba245"


@app.route("/", methods=["GET"])
def index():
    return render_template("register.html")


@app.route("/save", methods=["POST"])
def save():
    username = request.form["username"]
    password = request.form["password"]
    stored_pwd = form.hash_pwd(password)
    salt = stored_pwd[:64]
    stored_pwd = stored_pwd[64:]
    with open("DB.csv", "a+") as db:
        db.write("{},{},{}\n".format(username, salt, stored_pwd))
    flash(f"Account created for {username}!", "success")
    print("User Registered Successfully!")
    return render_template("login.html")


@app.route("/verify", methods=["GET", "POST"])
def verify():
    if request.method == "GET":
        return render_template("login.html")
    user_name = request.form["username"]
    password = request.form["password"]
    with open("DB.csv", "r") as db:
        for line in db:
            check = False
            if user_name in line:
                found_user_details = line
                check = True
                break
        if check:
            flash(f"{user_name} Exists in DB!", "success")
            print("User Exists")
            found_user, found_salt, found_hash = map(str, found_user_details.split(","))
            if form.verify_pwd(found_salt, found_hash.rstrip(), password):
                flash(f"Welcome {user_name}!", "success")
                print("Valid User!")
            else:
                flash("Login Unsuccessful. Incorrect password", "danger")
                print("Error incorrect password!")
        else:
            flash("Login Unsuccessful. User doesn't exist", "danger")
            print("User Doesn't Exists")
    return render_template("login.html")


if __name__ == "__main__":
    app.run(debug=True)
    app.run(host="0.0.0.0")
