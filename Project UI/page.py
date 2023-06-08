from flask import *
app= Flask(__name__)

@app.route('/')
@app.route('/home')
def main_page():
    return render_template('mainpg.html')





