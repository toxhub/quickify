from __future__ import print_function

import os
import sys
import shlex
import optparse
import subprocess

os.chdir(os.path.dirname(__file__) or '.')

original_argv = sys.argv[1:]

parser = optparse.OptionParser()

parser.add_option('--debug',
    action='store_true',
    dest='debug',
    help='also build debug build')


(options, args) = parser.parse_args()


def B(value):
  """Returns 1 if value is truthy, 0 otherwise."""
  return 1 if value else 0

def run(output):
  p = subprocess.Popen([output['exec'], ' ' ,output['execPath']], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
  while p.poll() is None:
        line = p.stdout.readline()
        line = line.strip()
        if line:
            print(str(line, 'utf-8'))

output = {
  'exec': 'cmake',
  'execPath': '.',
  'variables': {},
}

output['variables']['is_debug'] = B(options.debug)

run(output)
