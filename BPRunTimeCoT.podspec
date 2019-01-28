
Pod::Spec.new do |s|

    s.name         = "BPRunTimeCoT"
    s.version      = "0.0.1"
    s.ios.deployment_target     = "8.0"
    s.summary      = "简介"
    s.homepage      = "https://github.com/freedom6xiaobai/BPTestRepository"
    s.social_media_url  = "https://www.baidu.com"
    s.license       = "MIT"
    # s.license    = { :type => "MIT", :file => "FILE_LICENSE" }
    s.author       = {"baipeng" => "freedomjustice66@gmail.com"}
    s.source       = { :git => "https://github.com/freedom6xiaobai/BPTestRepository.git", :tag => s.version}
    s.requires_arc  = true
    s.source_files  = 'runtiime/*'
    #s.public_header_files = 'runtime/TFRuntimeManager.h'

end
