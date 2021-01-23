%% Clear all
clear all; clc
%% Classes
NO_MOVEMENT = 0;
APPROACH = 1;
MOVE_AWAY = 2;
%% Read CSV files
dirPath = "C:\Projekty\VisualStudio\StairsVisualStudio\MovementSensorController\Dataset\PyCharm";
csvFileNames = [
    "TEST_CONV_DIFF_APPROACH.csv";
    "TEST_CONV_DIFF_MOVE_AWAY.csv";
    "TEST_CONV_DIFF_NO_MOVEMENT.csv";
    
%     "TEST_CONV_DIST_APPROACH.csv";
%     "TEST_CONV_DIST_MOVE_AWAY.csv";
%     "TEST_CONV_DIST_NO_MOVEMENT.csv";
];
dataset = table();
for i=1:size(csvFileNames, 1)
    dataset = [dataset; readtable(fullfile(dirPath, csvFileNames(i)))];
end
dataset = removevars(dataset,{'Var1'});
dataset = dataset(randperm(size(dataset,1)), :);

% Delete unused variables
clear i csvFileNames dirPath
%% Run ClassificationLearner
classificationLearner

%% Save to file
save("trainedModel.mat", 'trainedModel')

%% Read model from file
load("trainedModel_1.mat");

%% Test model
T = removevars(dataset,{'GroundTruth'});
T = T(1:6, :);
yfit = trainedModel.predictFcn(T);

%% To read
help fitcknn
% Dla k=1 uzyskuje się 'minimum distance classifier matlab'

%% I Am Speed
% 3 - 4 miles per hour - Walking
% 4 - 6 miles per hour - Jogging
%  ~15  miles per hour - Running

% 250 ms - System reaction time - GOAL TO REACH
