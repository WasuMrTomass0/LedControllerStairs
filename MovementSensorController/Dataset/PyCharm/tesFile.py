import pandas as pd

NO_MOVEMENT = 0
APPROACH = 1
MOVE_AWAY = 2


def getName(_id: int):
    if _id == NO_MOVEMENT:
        return 'NO_MOVEMENT'
    if _id == APPROACH:
        return 'APPROACH'
    if _id == MOVE_AWAY:
        return 'MOVE_AWAY'
    return 'NotFound'


CONVERT_ID = 'TEST_CONV'

filePaths = [
    ('DS1_BrakRuchuCzujnikaDoSciany.txt', NO_MOVEMENT),
    ('DS1_OddalanieCzujnikaOdSciany.txt', MOVE_AWAY),
    ('DS1_PrzyblizanieCzujnikaDoSciany.txt', APPROACH)
]

directoryPath = r'C:\\Projekty\\VisualStudio\\StairsVisualStudio\\MovementSensorController\\Dataset\\'

NO_OF_MEAS = 10

# # # # Lists storing last measurements # # # #
storage_diff = [None] * NO_OF_MEAS
storage_dist = [None] * NO_OF_MEAS
# # # # # # # # # # # # # # # # # # # # # # # #
output_diff = []
output_dist = []
# # # # # # # # # # # # # # # # # # # # # # # #

for file in filePaths:
    path = directoryPath + file[0]

    with open(path, 'r') as token:
        text = token.read()
    text = text.split('\n')

    cnt = 0
    for line in text:
        if len(line) == 0 or line[0] == '#':
            continue
        if line[-1] == '.':
            line = line[:-1]  # Delete dot sign
        if line[0] == '-':

            # Reset and continue
            cnt = 0
            continue
            pass  # if line[0] == '-'

        _, diff, dist = [int(x) for x in line.split(',')]
        cnt += 1
        # # # #
        storage_diff = [diff] + storage_diff[:-1]
        storage_dist = [dist] + storage_dist[:-1]
        # # # #

        if cnt > NO_OF_MEAS:  # Store measurements
            output_diff.append(storage_diff + [file[1]])
            output_dist.append(storage_dist + [file[1]])
            pass  # if cnt > NO_OF_MEAS
        pass  # for line in text

    # Create pandas data frames and save as CSV
    colNames = ['n_' + str(x) for x in range(NO_OF_MEAS)] + ['GroundTruth']
    pd.DataFrame(output_dist, columns=colNames).to_csv(
        CONVERT_ID + '_DIST_' + getName(file[1]) + '.csv')
    pd.DataFrame(output_diff, columns=colNames).to_csv(
        CONVERT_ID + '_DIFF_' + getName(file[1]) + '.csv')

    pass  # for file in filePaths

# print(output_dist)
# print(output_diff)
