# Let's define a common build environment first...
project_name = 'CPPExpressionParser' 
project_src = 'src'
env = Environment()
isWindows =  "win" in env['PLATFORM']
if isWindows:
  buildType='debug'
  include_path=['E:\\Claudio\\VisualStudio\\CrossPlatform\\AmazonInterviewTraining\\include','E:\\Boost_1_55\\include\\boost-1_55']
  libs_path='E:\\Claudio\\VisualStudio\\CrossPlatform\\AmazonInterviewTraining\\build\\{build_type}'.format(build_type=buildType)
  extraLibPaths=['E:\\Boost_1_55\\lib']
  commonLibs=[] 
  commonDefines=['DEBUG']
  commonCFlags=['/MT', "/EHsc",'-O2']
  commonLFlags=["/DEBUG","/INCREMENTAL:NO", "/LTCG", "/SUBSYSTEM:CONSOLE"]
  common_env = Environment(MSVC_USE_SCRIPT= "c:\\Program Files (x86)\\Microsoft Visual Studio 12.0\\VC\\bin\\vcvars32.bat")
  common_env['TARGET_ARCH']='x86'
else: 
  common_env = Environment()
common_env.Append(CPPDEFINES={'VERSION': 1})
    
# We define our debug build environment in a similar fashion...
debug_env = common_env.Clone()
debug_env.VariantDir('build/{build_type}'.format(build_type=buildType), project_src)

# Now that all build environment have been defined, let's iterate over
# them and invoke the lower level SConscript files.
for mode, env in dict(debug=debug_env).iteritems():
    env.SConscript('build/%s/SConscript' % mode, exports=['env', 'include_path', 'libs_path','extraLibPaths', 'commonLibs','commonDefines','commonCFlags','commonLFlags'])


