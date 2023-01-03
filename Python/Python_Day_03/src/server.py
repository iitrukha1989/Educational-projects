from flask import Flask, render_template, request, url_for, redirect, Response
from pathlib import Path
import os


BASE_DIR = str(Path(__file__).parent)

app = Flask(__name__)


@ app.route('/', methods=["GET"])
def show_entries():
    agrs = dict()
    agrs["method"] = "GET"
    stream_entries = return_dir_and_file()
    return render_template(
        'index.html',
        args=agrs,
        stream_entries=stream_entries)


@ app.route("/upload", methods=["POST"])
def upload():
    args = {}
    if request.method == "POST":
        file = request.files['file']
        file.save(f'{BASE_DIR}/music/{file.filename}')
        args["method"] = "POST"
    return redirect(url_for('show_entries'))


def return_dir_and_file():
    id_index = 0
    res_list = list()
    file_list = os.listdir(f'{BASE_DIR}/music')
    for file_name in file_list:
        if file_name != '.DS_Store':
            id_index += 1
            res_list.append({'id': id_index,
                            'name': file_name[:file_name.rfind('.')],
                             'link': f'/music/{file_name}'})
    return res_list


@app.route('/files/<file_name>')
def streammp3(file_name):
    def generate():
        data = return_dir_and_file()
        for item in data:
            if item['id'] == file_name:
                song = item['link']
        with open(song, "rb") as fwav:
            data = fwav.read(1024)
            while data:
                yield data
                data = fwav.read(1024)
    if file_name.split(".")[-1] == "mp3":
        return Response(generate(), mimetype="audio/mpeg")


def main():
    app.run(debug=True, port=8888)


if __name__ == '__main__':
    main()
