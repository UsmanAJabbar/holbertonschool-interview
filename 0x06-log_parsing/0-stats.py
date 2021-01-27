#!/usr/bin/python3
from sys import stdin, stdout
import traceback

status_codes = {'200': 0, '301': 0,
                '400': 0, '401': 0, '403': 0, '404': 0, '405': 0,
                '500': 0}
file_size = 0
line_count = 0


def log_parser(log_line: str):
    """
    ------------------
    METHOD: log_parser
    ------------------
    Description:
        The log parser function takes counts valid
        status codes present in a log file.

        Each and every line is expected to follow this format
        <IP Add> - [<date>] "GET /path HTTP/1.1" <status code> <file size>
    Args:
        @log_line: log_line contains the string
        in the format above.
    Return:
        None
    """
    global line_count, file_size

    # Update Global Variables
    line_count += 1
    file_size += int(log_line.split()[-1])

    # Update Status Code Dictionary
    status_code = log_line.split()[-2]
    if status_code in status_codes.keys():
        status_codes[status_code] += 1


def status():
    """
    --------------
    METHOD: status
    --------------
    Description:
        Prints out the counts from file size
        and status_codes
    """
    print('File size: ' + str(file_size))
    for key, value in sorted(status_codes.items()):
        if value != 0:
            print('{}: {}'.format(key, value))


# Main
try:
    for line in stdin:
        log_parser(line.rstrip())
        if line_count % 10 == 0:
            status()

    # Ensure that if we have 11 elements,
    # the extra element gets a final print out.
    if line_count % 10 > 0:
        status()

except KeyboardInterrupt as e:
    traceback.print_exc(file=stdout)

except BrokenPipeError:
    pass
