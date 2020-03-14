import os
import subprocess

def cmd(c):
    process = subprocess.Popen(c, stdout=subprocess.PIPE, shell=True)
    output, error = process.communicate()

cmd("mkdir converted")

i = 0

for f in [f for f in os.listdir('.') if os.path.isfile(f)]:
    bash = ("ffmpeg -i '" + f + "' -vf scale=640:-1 -map 0 '_" +
            f + "'")

    cmd(bash)
    cmd("mv '_" + f + "' converted/'" + f + ".mkv'")

    i = i + 1

cmd("exit;exit")
