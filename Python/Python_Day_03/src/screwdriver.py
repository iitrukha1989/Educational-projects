from server import return_dir_and_file
import requests
import argparse


def upload(upload_file):
    with open(upload_file, "rb") as f:
        requests.post("http://127.0.0.1:8888/upload",
                      files={"file": f},)


def main():
    parser = argparse.ArgumentParser(description='')
    parser.add_argument("type_action", type=str, help="Action.")
    parser.add_argument("file_music", type=str, nargs='*', help="Path file.")
    args = parser.parse_args()
    if args.type_action == "upload":
        upload(args.file_music[0])
    elif args.type_action == "list":
        print(return_dir_and_file())


if __name__ == '__main__':
    main()
