import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    # The file to open is from user input
    file_name = sys.argv[1]

    # Empty list to store database
    csv_database = []
    subsequences = []

    # Empty list to store sequence
    sequence_txt = []

    with open(file_name, "r") as csvfile:
        csv_reader = csv.DictReader(csvfile)

        # Populate list of short tandem repeats (STRs)
        subsequences = csv_reader.fieldnames[1:]

        # Store values in database variable
        for row in csv_reader:
            # Add to database list
            csv_database.append(row)
    print(csv_database)

    # TODO: Read DNA sequence file into a variable
    dna_sequence = sys.argv[2]

    with open(dna_sequence, "r") as dna_seq:
        dna_reader = csv.reader(dna_seq)

        for i in dna_reader:
            # Store values in empty list
            sequence_txt.append(i)
    # print(sequence_txt)


    # TODO: Find longest match of each STR in DNA sequence
    # Empty dict
    long_match = {}
    # Finding longest match
    for subsequence in subsequences:
        long_match[subsequence] = longest_match(sequence_txt, subsequence)

    # TODO: Check database for matching profiles
    for person in csv_database:
        # Initiate match at 0
        match = 0
        for subsequence in subsequences:
            if person[subsequence] == str(long_match[subsequence]):
                # Add 1 to match
                match += 1
        # If all subsequences match
        if match == len(subsequences):
            print(person["Name"])

    # Else
    print("No match")

    return 0

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
