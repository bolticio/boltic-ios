Pod::Spec.new do |s|
    s.name             = 'boltic-ios'
    s.version          = '0.0.1'
    s.summary          = 'A framework to validate and track events.'
  
  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  
    s.description      = <<-DESC
  TODO: Add long description of the pod here.
                         DESC
  
    s.homepage         = 'https://github.com/bolticio/boltic-ios'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'sagargen' => 'sagarkumar@gofynd.com' }
    s.source           = { :git => 'https://github.com/bolticio/boltic-ios.git', :tag => s.version.to_s }
  
    s.ios.deployment_target = '12.0'
      
    s.vendored_frameworks = 'Frameworks/FyndAnalytics.xcframework'

  end
  