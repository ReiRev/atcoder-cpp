"""Test code for atcoder."""
import subprocess
import shutil
import argparse

parser = argparse.ArgumentParser(description='Test script for atcoder.')
parser.add_argument('--contest', '-c', type=str,
                    help='Contest name', required=True)
parser.add_argument('--problem', '-p', type=str,
                    help='Problem name', required=True)
parser.add_argument('--test_folder', '-t', type=str, default='test',)

args = parser.parse_args()

# remove tst folder
shutil.rmtree(args.test_folder, ignore_errors=True)

site = 'https://atcoder.jp/contests'
dst = \
    f'{site}/{args.contest}/tasks/{args.contest}_{args.problem}'
subprocess.run(
    ['oj', 'd',
     dst],
    check=True)

subprocess.run(['g++', '-std=c++17', '-Wall', '-O2', '-o',
               'a.out', f'{args.contest}/{args.problem.upper()}.cpp'],
               check=True)

subprocess.run(['oj', 't', '-c', './a.out', '-d',
               args.test_folder], check=True)
