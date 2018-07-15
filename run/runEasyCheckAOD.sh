#!/bin/sh
NEVENTS=100
INPUT_DIR="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHitWide/DIR_noRpcHitWide_user.yfukuhar.14514992.EXT0._000001.RDO.pool.root/"
FILE_PATTERN="AOD.*.root"
OUT_DIR="./tmp_output/"
if [ -d "$OUT_DIR" ] ; then
  rm -rvf $OUT_DIR
fi

COMMAND="root -l -b -q '$ROOTCOREDIR/scripts/load_packages.C' 'TestRun.cxx(${NEVENTS}, \"${OUT_DIR}\", \"${INPUT}\", \"${FILE_PATTERN}\")'"

echo "INPUT: "${INPUT}
echo "OUT_DIR: "${OUT_DIR}
echo "COMMAND:"${COMMAND}

eval $COMMAND

