Pod::Spec.new do |s|
    s.name     = 'Map4dServices'
    s.version  = '2.5.0'
    s.summary  = 'Map4D Services SDK for iOS'
    s.homepage = 'https://map4d.vn'

    s.author   = { 'IOTLink' => 'admin@iotlink.com.vn' }
    s.license  = {
        :type => "Copyright",
        :text => "Copyright (c) 2025 IOTLink"
    }

    s.platform = :ios, '12.0'
    s.source   = { :git => 'https://github.com/map4d/map4d-services-ios-sdk.git', :tag => s.version.to_s }

    s.ios.vendored_frameworks = 'sdk/Map4dServices.xcframework'
end
