///////////////////////////////////////////////////////////////////////////////////////
///////// > openSMILE configuration file for data output <           //////////////////
/////////                                                            //////////////////
///////// (c) audEERING GmbH,                                        //////////////////
/////////     All rights reserverd.                                  //////////////////
///////////////////////////////////////////////////////////////////////////////////////


/*
   This file can be included as data output file for standard feature
   extraction configuration files. It provides commandline options
   for the batch extraction GUI, and supports LLD and Functionals (summaries)
   saving.

   It requires the main extrator configuration file to provide the following
   data memory levels:  lld, lld_de, and func
 */

  //////////////////////////////////////////////////////////////////////
 ///////////////////  data output configuration  //////////////////////
//////////////////////////////////////////////////////////////////////

;;;;;;;;; output LLD features to CSV ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[componentInstances:cComponentManager]
instance[arffsink].type=cArffSink


[arffsink:cArffSink]
reader.dmLevel=func
frameIndex = 0
frameTime = 0
filename=\cm[output(O){?}:name of WEKA Arff output file, set to a valid filename to enable this output sink]
relation=\cm[corpus{Emotion}:arff relation attribute, feature set name and/or corpus name]
;;instanceName=\cm[instname]
instanceName=\cm[instname(N){noname}:name of arff instance]
 ;; use this line instead of the above to always set the instance name to the
 ;; name of the input wave file
 ;instanceName=\cm[inputfile]
;;\{\cm[arfftargetsfile{arff_targets.conf.inc}:name of arff targets include file]}

;; name of class label
class[0].name = emotion
 ; list of nominal classes OR "numeric"
class[0].type = \cm[classes{classA,classB,classC}:all classes for arff file attribute]
 ; the class label or value for the current instance
target[0].all = \cm[classlabel(a){unknown}:instance class label]
 ; append to an existing file, so multiple calls of SMILExtract on different
 ; input files append to the same output ARFF file
append=0
errorOnNoOutput = 1
